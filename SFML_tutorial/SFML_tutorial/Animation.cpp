#include "Animation.h"



Animation::Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0;
	currentImage.x = 0;

	//calculate height and width of each tux
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		//switches the current image
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			//this will set the animation back to the begining
			currentImage.x = 0;
		}
	}
	//set the offset of left and top of uvRect
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);

	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}


}

Animation::~Animation()
{
}
