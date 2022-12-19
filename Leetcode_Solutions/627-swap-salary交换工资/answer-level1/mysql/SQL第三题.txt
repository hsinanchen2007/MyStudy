`update salary set sex= char(ascii('f')+ascii('m')-ascii(sex));`
了解到了SQL语言中也可以利用ascii码，而且也能利用char进行数据类型强制转换