// ДАННЫЙ ПРИМЕР ИЩЕТ I2C-FLASH МОДУЛИ НА ШИНЕ И ВЫВОДИТ ИНФОРМАЦИЮ О НИХ.  // * Строки со звёздочкой являются необязательными.
                                                                            //
const uint8_t sum = 10;                                                     //   Определяем количество модулей на шине I2C. Допускается указывать значение превышающее реальное количество модулей.
                                                                            //
#include <Wire.h>                                                           // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Address.h>                                           //   Подключаем библиотеку для работы с адресами модулей линейки I2C-flash.
iarduino_I2C_Address j[sum];                                                //   Объявляем массив объектов (j), указав количество (sum) модулей I2C-flash на шине I2C. Адреса модулей будут определены автоматически.
                                                                            //
void setup(){                                                               //
     delay(500);                                                            // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                                                    //   Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
     while(!Serial){;}                                                      // * Ждём завершения инициализации шины UART.
     for(int i=0; i<sum; i++){                                              //   Проходим по всем модулям ...
       j[i].begin();                                                        //   Инициируем работу с модулями ...
       if(j[i]){                                                            //   Если модуль инициирован ...
         Serial.print(i+1);                                                 // * Выводим порядковый номер модуля.
         Serial.print(F(".) Модуль "));                                     // *  
         switch( j[i].getModel() ){                                         //   Сравниваем номер модели модуля ...
           case 0x01: Serial.print(F("кнопка"                    )); break; //   Если номер модели модуля равен 0x01, значит это кнопка.
           case 0x02: Serial.print(F("светодиод"                 )); break; //   Если номер модели модуля равен 0x02, значит это RGB светодиод.
           case 0x03: Serial.print(F("потенциометр"              )); break; //   Если номер модели модуля равен 0x03, значит это потенциометр.
           case 0x04: Serial.print(F("звукоизлучатель"           )); break; //   Если номер модели модуля равен 0x04, значит это звукоизлучатель.
           case 0x05: Serial.print(F("датчик влажности DHT"      )); break; //   Если номер модели модуля равен 0x05, значит это датчик влажности и температуры.
           case 0x06: Serial.print(F("датчик освещённости DSL"   )); break; //   Если номер модели модуля равен 0x06, значит это датчик освещённости.
           case 0x07: Serial.print(F("расширитель выводов"       )); break; //   Если номер модели модуля равен 0x07, значит это расширитель выводов.
           case 0x08: Serial.print(F("светодиодная матрица 8x8"  )); break; //   Если номер модели модуля равен 0x08, значит это светодиодная матрица 8x8.
           case 0x09: Serial.print(F("энкодер"                   )); break; //   Если номер модели модуля равен 0x09, значит это энкодер с поддержкой функции потенциометра.
           case 0x0A: Serial.print(F("реле на 2 канала"          )); break; //   Если номер модели модуля равен 0x0A, значит это электромеханическое реле на 2 канала.
           case 0x0B: Serial.print(F("реле на 4 канала"          )); break; //   Если номер модели модуля равен 0x0B, значит это твердотельное реле на 4 канала.
           case 0x0C: Serial.print(F("силовой ключ на 4N-канала" )); break; //   Если номер модели модуля равен 0x0C, значит это силовой ключ на 4 N-канала.
           case 0x0D: Serial.print(F("силовой ключ на 4P-канала" )); break; //   Если номер модели модуля равен 0x0D, значит это силовой ключ на 4 P-канала.
           case 0x0E: Serial.print(F("силовой ключ на 4N-канала" )); break; //   Если номер модели модуля равен 0x0E, значит это силовой ключ на 4 N-канала, с измерением тока.
           case 0x0F: Serial.print(F("силовой ключ на 4P-канала" )); break; //   Если номер модели модуля равен 0x0F, значит это силовой ключ на 4 P-канала, с измерением тока.
           case 0x10: Serial.print(F("бампер с датчиками линий"  )); break; //   Если номер модели модуля равен 0x10, значит это бампер с датчиками линий.
           case 0x11: Serial.print(F("джойстик"                  )); break; //   Если номер модели модуля равен 0x11, значит это джойстик.
           case 0x12: Serial.print(F("LCD конвертер в I2C"       )); break; //   Если номер модели модуля равен 0x12, значит это адаптер для LCD дисплеев 1602/2004.
           case 0x13: Serial.print(F("клавиатура"                )); break; //   Если номер модели модуля равен 0x13, значит это клавиатура.
           case 0x14: Serial.print(F("мотор-редуктор с драйвером")); break; //   Если номер модели модуля равен 0x14, значит это мотор.
           case 0x15: Serial.print(F("реле на 1 канал"           )); break; //   Если номер модели модуля равен 0x15, значит это электромеханическое реле на 1 канал.
           case 0x16: Serial.print(F("LED индикатор на 4 разряда")); break; //   Если номер модели модуля равен 0x16, значит это 4-разрядный LED индикатор.
           case 0x17: Serial.print(F("ИК-приёмопередатчик"       )); break; //   Если номер модели модуля равен 0x17, значит это ИК-приёмопередатчик.
           case 0x18: Serial.print(F("трассы ИК"                 )); break; //   Если номер модели модуля равен 0x18, значит это ИК-модуль трассы.
           case 0x19: Serial.print(F("TDS/EC-метр"               )); break; //   Если номер модели модуля равен 0x19, значит это TDS/EC-метр.
           case 0x1A: Serial.print(F("pH-метр"                   )); break; //   Если номер модели модуля равен 0x1A, значит это pH-метр.
           default:   Serial.print(F("не определён"              )); break; //   Если в 0 элементе массива k хранится иное значение, значит этот модуль был создан позднее чем данный скетч, или на одном адресе находятся несколько устройств.
         }            Serial.print(F(", адрес на шине I2C = 0x"  ));        // *
                      Serial.print(j[i].getAddress(), HEX         );        // * Выводим адрес модуля на шине I2C.
                      Serial.print(F(", версия прошивки "        ));        // *
                      Serial.print(j[i].getVersion()              );        // * Выводим версию прошивки модуля.
                      Serial.print(F(", подтяжка линий шины I2C "));        // *
                      Serial.print(j[i].getPullI2C()? "в":"от"    );        // * Выводим начало стлова "в"ключена или "от"ключена.
                      Serial.print(F("ключена.\r\n"              ));        //
       }                                                                    //
     }                                                                      //
}                                                                           //
                                                                            //
void loop(){                                                                //
}                                                                           //