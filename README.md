
## Proyecto final de curso de Robotica

El proyecto consta de un robot explorador basado en Arduino Mega 2560, el cual posee sensores y actuadores para funcionar, el codigo esta escrito en C++ con el IDE de arduino:

> Sensores

* Sensor ultrasonico

Detecta proximidad, al estar a 10cm el robot ejecuta un giro hasta encontrar un camino adecuado

* Sensor LDR

Busca fuentes luminicas hacia donde ir siempre en direccion hacia la mayor intensidad ajustando su direccion

* Sensores infrarrojos

El modo de infrarrojos realiza movimientos de los motores para mantenerlo siempre sobre una linea dibujada en el suelo


> Selector de modos

Mediante un control remoto externo y un receptor infrarrojo se pueden seleccionar modos:

* Modo infrarrojo: Selecciona el modo de seguidor de linea
* Modo ultrasonico: Ejecuta el modo de proximidad
* Modo LDR: Busca fuente luminica




![RoverIMG](https://scontent.fros2-1.fna.fbcdn.net/v/t39.30808-6/270041325_10209803255754003_744850291609743981_n.jpg?_nc_cat=108&ccb=1-5&_nc_sid=730e14&_nc_ohc=2QVXpoF5qgQAX-Dxxmt&_nc_ht=scontent.fros2-1.fna&oh=00_AT9wgPyT5wLf8ST7UyFeDxloIIWy1A-rGmWiUiVynRUwdA&oe=61D7B9F9)
