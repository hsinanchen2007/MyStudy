### 解题思路
1、a,b 字符串排序后相等证明a,b长度相同，每个字符的个数都相同
2、定义数组c,d;将a,b 相同index但是值不同的字符分别放到c,d中
3、判断c,d 长度为0，证明a,b相同，此时判断a的长度不等于a.uniq的长度，证明a中有重复的字符，可交换然后变成b
4、判断c,d排序后相等且长度为2，c,d的字符元素相同，顺序不同；表示a和b相同索引，不同值的字符有2个，交换后a可变成b；
### 代码

```ruby
# @param {String} a
# @param {String} b
# @return {Boolean}
#数组可以直接使用sort方法，如c.sort  ; 字符串需要对chars才能用sort   如a.chars.sort ，uniq方法同样如此
def buddy_strings(a, b)
    if a.chars.sort!=b.chars.sort
        # 只有一个返回e，如果 第一个条件 a.chars.sort!=b.chars.sort 是直接return false 而不是返回e =false ，会报错
        e= false 
    else
        #定义数组
        c=[]
        d=[]
        for i in 0...a.length
                if a[i] != b[i]
                    c.push(a[i])
                    d.push(b[i])
                end
        end
        if c.sort != d.sort
            e=false 
        elsif c.sort == d.sort  and c.length ==2
            e=true
        #需要考虑到a 和 b两个字符串相同的情况，如果a和b 相同并且有重复的字符，那么a两个重复字符的交换也还是等于b     
        elsif c.length == 0 and a.chars.uniq.length != a.length 
            e=true
        else
            e=false
        end
    end
    return e 
    
end
```