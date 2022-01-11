##### 1.we can download the raw data from 

https://www.ripe.net/analyse/internet-measurements/routing-information-service-ris/ris-raw-data

##### 2.then we use bgpdump to  parse bgp routing tables

```
 bgpdump -m
```

##### 3.we will get the bgp table like this 

![1641886980036](C:\Users\huge\AppData\Roaming\Typora\typora-user-images\1641886980036.png)

##### 4.we can use this program to get the FIB

![1641887063884](C:\Users\huge\AppData\Roaming\Typora\typora-user-images\1641887063884.png)

