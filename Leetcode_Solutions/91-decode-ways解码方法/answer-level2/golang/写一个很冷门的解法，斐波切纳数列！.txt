居然不止我一个写go题解，看见go先别走啊，基本认识英语就读的懂的语言，看完再走行吗...
动态规划，动态规划，动态规划，看起来千篇一律，这里玩点特别的。
1个小于3的字符（不含0）可以组成1种解法，两个就是2种(1+1)，三个是3种(1+2)，4个是五种(2+3)...
即从第二个开始的斐波切纳数列，（可以理解为最后一个为一个解和两个为一个解合并出来的）具体通解可以去看百度百科！我们把不是1和2的点视为断点将字符串切开，统计每段的可能累乘就好啦！
那么开始区分各种情况：
1. 字符为1，2式统计长度count；
2. 遇到3 4 5 6结尾时，取count-1与count位（前一项只会是1，2）做和后累乘，count置1；
3. 7 8 9要检查前一位是否为1，如果是和2相同处理，不是则只取count-1位累乘，count置1；
4. 0的时候必须和前一位合并才有意义故取count-1位累乘，count置1；
5. 额外要注意的是，当最后一位为1 2时，没有被累乘，还需要再算一次进行累乘。
```
func numDecodings(s string) int {
    if len(s)==0{
        return 0
    }
    var ans,count float64
    count,ans=1,1
    l,r,m:=(1+math.Sqrt(5))/2,(1-math.Sqrt(5))/2,1/math.Sqrt(5)
    for i:=0;i<len(s);i++{
        if s[i]>'2'{
            tmp:=(math.Pow(l,count-1)-math.Pow(r,count-1))*m+(math.Pow(l,count)-math.Pow(r,count))*m  

            if s[i]>='7'{
                if i!=0&&s[i-1]!='1'{
                    tmp-=(math.Pow(l,count-1)-math.Pow(r,count-1))*m

                }
            }
            ans=ans*tmp
            fmt.Println(ans)
            count=1

        }else{
            if s[i]=='0'{
                ans=ans*((math.Pow(l,count-1)-math.Pow(r,count-1))*m)
                count=1
            }else{
            count++
            }
        }
    }
 
    if count!=1{
    ans=ans*(math.Pow(l,count)-math.Pow(r,count))*m
    }
    return int(math.Floor(ans + 0.5))
}
```
这样的算法会用算力内存大约是2MB，看了眼C++的题解，内存省了好多不知道是不是编译器的问题，不过一共就引入3个额外变量（LMR我就是懒得粘让电脑一遍一遍算了），就是拿算力换空间，不过第二次刷更是速度从25+变成100，抽什么风...
如果数据很短甚至可以直接求出几个值直接写hashmap,应该比一个一个试快。
PS:吐槽golang里拿个脑回路清奇的四舍五入...
