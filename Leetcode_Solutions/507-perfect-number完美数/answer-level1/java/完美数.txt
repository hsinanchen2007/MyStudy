**思路：** 获取所有除参数本身的因子，我的做法是从1开始遍历致这个数的算术平方根。
```
算术平方根：x^2 = a,这个非负数x就是a的算术平方根。
```
在这个范围内可以被参数整除的两个因子，除了是参数本身这个条件，剩下的因子都储存在一个set集合中，
遍历结束后set集合求和，并对比参数，相等返回true,不等返回false.
```java []
public boolean checkPerfectNumber(int num) {
        if(num==0||num==1)return false;
        HashSet<Integer> objects = new HashSet<Integer>();

        for(int i = 1;i<num/2;i++){
            if(i*i>num)break;
            if(num%i==0){
                int i1 = num / i;
                if(i1!=num){
                    objects.add(i1);
                }
                objects.add(i);
            }
        }
        int sum = 0;
        for (Integer i :objects
             ) {
            sum += i ;
        }
        return sum==num?true:false;
    }
```



    