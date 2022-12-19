定义n!的方法；定义Cmn = m!/[(m-n)!*n!]  
当楼梯数n为偶数,一阶一阶上楼梯 Cmn(n,0);
只踏1个2阶其余一阶上楼梯方法有 Cmn(n-1,1);
只踏2个2阶其余一阶上楼梯方法有 Cmn(n-2,2);
依次类推,求和 Cmn(n-i,i) ，i的取值为0到n/2；包含0，n/2
当楼梯数n为奇数数,i的取值为0到（n-1）/2 ；包含0，（n-1）/2

```
# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
    sum = 0
    if n<=3
       return n
    elsif n % 2 == 0 
        for i in 0..(n/2)
            y = Cmn(n-i,i)
            sum = sum +y
        end
        return sum
    elsif n % 2 == 1
        for i in 0..(n-1)/2
            y = Cmn(n-i,i)
            sum = sum +y
        end
        return sum
    end
end
def Cmn(m,n)
     x=jiecheng(m)/jiecheng(m-n)
     y=x/jiecheng(n)
     return y
end
def jiecheng(m)
    a=1
    if m == 0 || m == 1
        return 1
    else 
        for i in 2..m
            a = a*i 
        end 
        return a
    end
end
```

