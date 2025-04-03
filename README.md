XBee Pro S2C ve Deneyap Kart 1A ile Radyo Haberleşmesi
Bu projede XBee Pro S2C modülleri ve Deneyap Kart 1A kullanılarak radyo haberleşmesi sağlanmaktadır. Deneyap 6-Eksen Ataletsel Ölçüm Birimi (IMU), X, Y ve Z eksenlerindeki ivme ve jiroskop değerlerini okurken; Deneyap Basınç Ölçer modülü, ortam basıncını hPa cinsinden ölçmektedir. Deneyap GPS ve GLONASS Konum Belirleyici sayesinde tarih, saat, enlem ve boylam bilgileri elde edilmektedir. Ayrıca, IMU'nun dahili sıcaklık sensörü kullanılarak ortam sıcaklığı hem °C hem de °F cinsinden ölçülür.
Veriler Deneyap Kart 1A tarafından işlenir ve koordinatör olarak yapılandırılmış XBee modülü üzerinden, router olarak yapılandırılmış XBee modülüne kablosuz olarak iletilir. Router olarak yapılandırılmış XBee modülü, bu verileri bilgisayara aktarmakta ve XCTU yazılımı üzerinden gerçek zamanlı olarak veriler izlenebilmektedir. Veri iletim frekansı 1 Hz olup her saniyede bir güncellenmiş telemetri verileri gönderilmektedir.
Ayrıca her veri iletimi gerçekleştiğinde Deneyap Kart 1A'ya bağlı dahili RGB LED, magenta renkli olarak yanıp sönerek iletim olduğunu göstermektedir. Bu görsel geri bildirim sayesinde sistemin çalışır durumda olup olmadığı kolayca takip edilebilmektedir.

Gerekli Donanım ve Yazılım
Donanım:
•	2 adet XBee Pro S2C modülü
•	2 adet XBee Explorer adaptörü
•	2 adet USB kablosu
•	Deneyap Kart 1A
•	Deneyap GPS ve GLONASS Konum Belirleyici 
•	Deneyap Basınç Ölçer 
•	Deneyap 6-Eksen Ataletsel Ölçüm Birimi
•	3 adet I2C bağlantı kablosu
•	Jumper kablolar
•	Breadboard
•	3.7V Li-Po batarya
Yazılım:
•	XCTU programı
•	USB Drivers for Digi radios and modems sürücüsü
•	Deneyap Kart IDE veya Arduino IDE

Adım 1: XBee Modüllerini Bağlama
1.	XBee modüllerini XBee Explorer adaptörlerine yerleştirin.
2.	USB kablosunu kullanarak her iki XBee Explorer'ı bilgisayarınıza bağlayın.

Adım 2: XCTU ile İlk XBee'yi Tanımlama 
1.	XCTU programını açın.
2.	"Discover radio devices" butonuna tıklayın (büyüteç simgesi).
3.	İlk XBee modülünün bağlı olduğu COM portunu seçin ve Next butonuna tıklayın.
4.	Set default seçeneğini işaretleyin.
5.	Modülün mevcut Baud Rate değerini seçin (bilmiyorsanız tüm değerleri seçin).
6.	Finish butonuna tıklayın, XBee cihazı aranacak.
7.	XBee bulunduğunda, cihazı seçin ve "Add selected devices" butonuna tıklayın.
8.	Eklendikten sonra XBee modülüne tıklayın ve Default butonuna basarak tüm değerleri varsayılana sıfırlayın.

Adım 3: XCTU ile İkinci XBee'yi Tanımlama 
1.	Yeni bir XCTU penceresi açın.
2.	"Discover radio devices" butonuna tıklayın.
3.	İkinci XBee'nin bağlı olduğu COM portunu seçin ve Next butonuna tıklayın.
4.	Set default seçeneğini işaretleyin.
5.	Modülün mevcut Baud Rate değerini seçin (bilmiyorsanız tüm değerleri seçin).
6.	Finish butonuna tıklayın, XBee cihazı aranacak.
7.	XBee bulunduğunda, cihazı seçin ve "Add selected devices" butonuna tıklayın.
8.	Eklendikten sonra XBee modülüne tıklayın ve Default butonuna basarak tüm değerleri varsayılana sıfırlayın.

Adım 4: İlk XBee'yi Koordinatör Olarak Ayarlama
1.	İlk XBee'nin olduğu XCTU penceresine geri dönün.
2.	"Network" başlığına gidin.
o	Ce (Coordinator/End Device Mode): Indirect Message Coordinator [1] olarak ayarlayın.
3.	"Networking & Security" sekmesine gidin.
o	ID (Network ID): İstediğiniz bir sayısal değer girin. Örneğin 7293 (aynı ID diğer modülde de kullanılmalıdır).
4.	"Addressing" sekmesine gidin.
o	NI (Node Identifier): “Koordinator” gibi anlaşılır bir isim girin.
o	DH (Destination Address High): İkinci XBee’nin SH (Serial Number High) değerini kopyalayıp buraya yapıştırın.
o	DL (Destination Address Low): İkinci XBee’nin SL (Serial Number Low) değerini kopyalayıp buraya yapıştırın.

Adım 5: İkinci XBee'yi Router Olarak Ayarlama
1.	İkinci XBee’nin XCTU penceresine geçin.
2.	"Network" başlığına gidin.
o	Ce (Coordinator/End Device Mode): Standard Router [0] olarak ayarlayın.
3.	"Networking & Security" sekmesine gidin.
o	ID (Network ID): İlk XBee’de girilen değerle aynı olmalı (7293).
4.	"Addressing" sekmesine gidin.
o	NI (Node Identifier): “Router” gibi anlaşılır bir isim girin.
o	DH (Destination Address High): İlk XBee’nin SH (Serial Number High) değerini kopyalayıp buraya yapıştırın.
o	DL (Destination Address Low): İlk XBee’nin SL (Serial Number Low) değerini kopyalayıp buraya yapıştırın.

Adım 6: Baud Rate Ayarlarını Güncelleme
1.	İlk XBee’nin XCTU penceresine geri dönün.
o	"Serial Interfacing" sekmesine gidin.
o	BD (Baud Rate): 57600 olarak ayarlayın.
2.	İkinci XBee’nin XCTU penceresine geçin.
o	"Serial Interfacing" sekmesine gidin.
o	BD (Baud Rate): 57600 olarak ayarlayın.
Adım 7: Ayarları Kaydetme
Hem birinci hem de ikinci XBee’nin XCTU programlarını açın.
Her iki XBee için de yapılan tüm ayarları kaydetmek amacıyla, her iki cihazın penceresinde bulunan "Write" butonuna tıklayın (kalem simgesi).
Adım 8: Donanım Bağlantıları
Koordinator olarak yapılandırılan Xbee Pro S2C modülünü, XBee Explorer adaptöründeki RX, TX, GND ve 5V pinleri aracılığıyla Deneyap Kart 1A'daki RX, TX, GND ve 5V pinlerine jumper kablo ile bağlayın.
Deneyap GPS ve GLONASS Konum Belirleyici, Deneyap Basınç Ölçer, Deneyap 6-Eksen Ataletsel Ölçüm Birimi modüllerini I2C haberleşme konnektörü aracılığıyla Deneyap Kart 1A'ya daisy-chain (zincirleme) konfigürasyonunda bağlayın.
Adım 9: Yazılım Yükleme
Deneyap Kart IDE veya Arduino IDE programlarından birini kullanarak kodu Deneyap Kart 1A'ya USB kablo aracılığıyla yükleyin. Kodu yükleme sırasında Deneyap Kart 1A üzerinde bulunan RX ve TX pinlerinin bağlantılarını geçici olarak kesin. Yükleme tamamlandığında bağlantıları tekrar sağlayın.
Adım 10: Haberleşme
Router olarak yapılandırılan xbee modülünüzü Explorer adaptör aracılığıyla bilgisayara bağlayın
XCTU programını açın.
"Discover radio devices" butonuna tıklayın (büyüteç simgesi).
İlk XBee modülünün bağlı olduğu COM portunu seçin ve Next butonuna tıklayın.
Set default seçeneğini işaretleyin.
Modülün mevcut Baud Rate değerini seçin (57600 olarak yapılandırdık).
Finish butonuna tıklayın, XBee cihazı aranacak.
XBee bulunduğunda, cihazı seçin ve "Add selected devices" butonuna tıklayın.
Eklendikten sonra XBee modülüne tıklayın.
"Switch to Console Working Mode" butonuna (sağ üst köşedeki monitör simgesi) tıklayın.
"Open the Serial Connection with the Radio Module" butonuna tıklayarak seri bağlantıyı başlatın.
Deneyap Kart 1A'ya bağlı koordinatör XBee modülünün gönderdiği veriler burada görüntülenecektir.

![XBeeRadioCommunicationwithDeneyapKart1ABoard](https://github.com/user-attachments/assets/88dfdf53-aeff-40a0-9de5-249d78c2a80c)

![4abe0e7e-b0c6-4056-94f2-a6ef0522f309](https://github.com/user-attachments/assets/3dfe99e9-1e3d-465c-a302-fffeb0021737)

![Ekran görüntüsü 2025-04-01 000006](https://github.com/user-attachments/assets/781e4b87-8829-4581-95f4-5b4e522bf308)







