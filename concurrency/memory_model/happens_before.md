Bir programın çalışma zamanında nasıl davranacağını kestirebilmemiz için şunları bilebilmemiz gerekir:
	- programdaki (farklı _thread_'ler tarafından gerçekleştirilebilecek) işlemlerin _(operasyonların)_ hangi sırayla yürütüleceği
	- programdaki bir işlemin/işlemlerin sonuçlarının (başka _thread_'ler tarafından yürütülebilecek) diğer bir işlem/işlemler yapılmadan görülür olup olmadığı

Tek bir _thread_'in söz konusu olduğu programlarda yukarıdaki soruların cevabı sezgisel olarak verilebilir.
Birden fazla _thread_'in söz konusu olduğu programlarda ise bu durum çok daha karmaşıktır.

#### happens-before ilişkisi

_A_ ve _B_ iki operasyon olsun. Bu operasyonlar aynı _thread_'de gerçekleştirilen operasyonlar olabildiği gibi farklı _thread_'lerde gerçekleştirilen operasyonlar da olabilir.
Eğer _A_ operasyonunun etkileri _B_ operasyonunu yürütecek _thread_'de _B_ operasyonu yürütülmeden önce görülür durumda ise

**A happens before B ** <br>

garantisi söz konusudur.

_happens-before_ ilişkisi "zamansal olarak daha önce gerçekleşme" ilişkisine göre çok daha güçlü bir durumdur.

Eğer _A_ operasyonu _B_ operasyonuna göre zamansal açıdan daha önce gerçekleştiriliyor ise bu _A_'nın etkilerinin _B_'yi yürütecek _thread_'de _B_ yürütülmeden önce görülür olma garantisi değildir. _caching_, _store buffer_ vs gibi mekanizmalar operasyonun etkilerinin diğer _thread_'lerde görülmesini geciktirebilir.

Daha erken zamanda oluşma garantisi _happens-before_ ilşkisi için gerek şarttır ancak yeter şart değildir.

#### sequenced before ilişkisi
sequenced-before ilişkisi aynı _thread_'deki işlemlere ilişkindir.

- _Sequenced-before_ ilişkisi geçişkendir _(transitive)_ 
A _sequenced before_ B  doğru ise
B _sequenced before_ C  doğru ise
A _sequenced before_ C  doğrudur.

```
x = 1; 		// A
y = 2; 		// B
z = x + 1;	// C
```

Aşağıdaki kodu ele alalım:<br>

```
y = a * x + b; // (y = ((a * x) + b);
```
Bu ifadede 3 işlem var: çarpma toplama ve atama. Burada<br>
çarpma işlemi  _sequenced before_ toplama işlemi <br>
toplama işlemi _sequenced before_ atama işlemi <br>
dolayısıyla <br>
atama işlemi _sequenced before_ toplama işlemi <br>

Eğer bir _thread_ için <br>
A _sequenced before_ B doğru ise <br>
A _happens before_ B doğrudur.<br>

Bu şu anlama geliyor:<br>
_sequenced-before_ ilişkisi aynı zamanda _thread_ içindeki _(intra-thread)_ happens before ilişkisine karşılık geliyor.<br>