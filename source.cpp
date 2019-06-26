#include  <iostream>
#include "obb.h"
using namespace std;

int main()
{
  float _x=10;
  float _y=0;
  float _width=10;
  float _height=10;
  float _rotation=0;
  obb *m_obb=new obb( _x,  _y,  _width,  _height, _rotation);
  //obb n_obb(_x+2*_width, _y+2*_height, _width+1, _height+1, _rotation);
  std::cout << "Num   x   y   width   height   flag " << std::endl;
  for (unsigned int i = 0; i < 1000; i++)
  {
	  float m_x = (rand() % 10001) / 1000.0;
	  float m_y= (rand() % 10001) / 1000.0;
	  float m_width= (rand() % 10001) / 1000.0;
	  float m_height = (rand() % 10001) / 1000.0;
	  float m_rotation= (rand() % 10001) / 1000.0;


	  obb n_obb(m_x, m_y, m_width, m_height, m_rotation);
	  bool flag = false;
	  flag = m_obb->intersects(n_obb);
	  
	  //std::cout <<"Num:"<<i+1<<"x:"<<m_x<<"y:"<<m_y<<"width"<<m_width<<"height:"<<m_height<<"flag:"<< flag << std::endl;
	  std::cout << i + 1 << "  " << m_x << "  " << m_y << "  " << m_width << "  " << m_height << "  " << flag << std::endl;

  }
  m_obb = NULL;
  delete[] m_obb;
  system("pause");

  return 0;
}
