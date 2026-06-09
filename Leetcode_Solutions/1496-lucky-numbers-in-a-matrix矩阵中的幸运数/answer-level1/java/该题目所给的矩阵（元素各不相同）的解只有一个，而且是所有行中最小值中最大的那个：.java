证明：
a(i,j)是行中最小 列中最大

则：	a(i,j)<a(i,...)//"..."中不包含a(i,j)
a(i,j)>a(...,j)

推导出
a(i,j)<a(i,j+b)
a(i,j)>a(i+k,j)

若存在另一个解a(i+k,j+b)，则符合
a(i+k,j+b)<a(i+k,...)
a(i+k,j+b)>a(...,j+b)

推导出
a(i+k,j+b)<a(i+k,j)<a(i,j)
a(i+k,j+b)>a(i,j+b)>a(i,j)

也就是说两者相等。即只有一个解

性质：
若a(i,j)为可行解，则符合两个条件（行中最小 列中最大）
a(i,j)<a(i,j+b1)  
a(i,j)>a(i+k1,j)

其他行中的最小值a(i+k1,j+b1)有如下性质
a(i+k1,j+b1)<a(i+k1,j)  

即，可行解是所有行最小值中的最大值
a(i+k1,j+b1)<a(i+k1,j)<a(i,j)