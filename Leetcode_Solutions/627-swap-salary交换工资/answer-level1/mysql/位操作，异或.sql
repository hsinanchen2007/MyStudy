update salary set sex = char(ascii('f') ^ ascii('m') ^ ascii(sex));

扩展：大小写相互转换也可以异或，异或32

扩展：任意两个字符相互转换，先异或求得差值，再异或就变成对方啦~