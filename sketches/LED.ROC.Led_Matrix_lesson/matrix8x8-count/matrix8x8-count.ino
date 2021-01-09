/*************************************************** 
  Эта библиотека разработана специально для модуля светодиодной матрицы 8x8 ROC

  ----> https://shop.robotclass.ru/index.php?route=product/product&product_id=733

  Данный модуль работает по интерфейсу I2C, используя два контакта SDA и SCL.
  Имеется возможность использовать разные адреса I2C. Для этого нужно разрезать
  или спаять специальные адресные перемычки на обратной стороне платы.
  Для модулей с двумя адресными пермычками можно выбрать один адрес из четырёх: 
  0x70, 0x71, 0x72 or 0x73. Для модулей с тремя адресными перемычками допустимы
  адреса с 0x70 по 0x77.

  RobotClass вкладывает много сил в создание уроков по основам электроники
  и программированию микроконтроллеров. Покупая наши продукты, вы помогаете
  нам создавать новые уроки и модули! 

  Автор: Олег Евсегнеев, RobotClass.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  matrix.begin(0x70);  // устанавливаем адрес модуля
  delay(1000); // пауза 1 секунда, можно убрать
}

void loop() {
  // запускаем цикл от символа '9' до символа '0'
  // что эквивалентно перебору чисела от 57 до 48
  for( char c='9'; c>='0'; c--){
     matrix.clear(); // очищаем буфер матрицы
     matrix.drawChar(0, 0, c, 1, 0, 1);
     matrix.writeDisplay(); // выводим буфер в матрицу
     delay(1000); // пауза 1 секунда
  }
}
