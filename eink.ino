void helloWorld()
{
 display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
//   // center the bounding box by transposition of the origin:
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(0, 10);
    display.print("Aussen");
    display.setCursor(175, 10);
    display.print("Innen");
    display.setFont(&FreeMonoBold24pt7b);
    display.setCursor(0, 50);
    display.print(tmpdraus_int);
    display.setCursor(180, 50);
    display.print(tmpwozi_int);
    display.setCursor(0, 120);
    display.print(humdraus_int);
    display.print("%");
    display.setCursor(180, 120);
    display.print(humwozi_int);
    display.print("%");
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(100, 95);
    display.print(batteryvoltage2);

    display.setCursor(100, 120);
    display.print(batteryvoltage);
  }
  while (display.nextPage());
//   display.setRotation(1);
//   display.setFont(&FreeMonoBold9pt7b);
//   display.setTextColor(GxEPD_BLACK);
//   int16_t tbx, tby; uint16_t tbw, tbh;
//   display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
//   // center the bounding box by transposition of the origin:
//   uint16_t x = ((display.width() - tbw) / 2) - tbx;
//   uint16_t y = ((display.height() - tbh) / 2) - tby;
//   display.setFullWindow();
//   display.firstPage();
//   do
//   {
//     display.fillScreen(GxEPD_WHITE);
//     display.setCursor(x, y);
//     display.print(HelloWorld);
//   }
//   while (display.nextPage());
}