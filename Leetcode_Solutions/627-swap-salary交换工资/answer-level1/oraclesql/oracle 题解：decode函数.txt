update salary s 
set s.sex =  decode(s.sex,'m','f','f','m');

decode(value, if1, then1, if2,then2, if3,then3, . . . else )
Value 可以放列
if 是出现的值
then 是你想要把if变成什么值
else 是都不匹配时的值，可忽略

例子：decode(sex,'1','男','2','女','其他');
sex 列的 值里出现的情况是 1 和 2 或者其他
这也是通常做为查询结果可以用到的

个人理解，如有不妥当的地方法请指出。
