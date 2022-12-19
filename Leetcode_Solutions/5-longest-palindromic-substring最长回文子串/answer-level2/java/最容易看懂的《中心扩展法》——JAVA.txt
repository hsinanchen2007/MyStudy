
### [STATEMENT]
这个解法也是**中心扩展法**， 但是，是本人自己想的(最初不知道这种方式还有专门的名称， 呵呵)。
后来看了官方使用这种方式的题解，发现和自己写的大同小异，但本人认为，*那里在处理最长字串的左右下标时，有些混乱，不易理解*，所以我分享一下我的写法，相信，大家在看懂了我这个，再看，那个，应该就没问题了。
### [CODE]
```java
class Solution{
    public String find(String s){
    //中心扩展法
        int Lol = 0; //记录最长字串的长度
        int len = s.length();
        int start = 0, end = 0; //最长字串边界
        for(int i = 0; i < len; i++){
            //最长字串长度为奇数的情况
	        int left = i - 1, right = i + 1; //记录最长字串的边界，直接从i下标的左右开始
            //odd为java的标签，实现指定跳转，类似c/c++的goto
            odd:for( ; left >= 0 && right < len; left--, right++){
                //当不满足直接跳出odd循环
                if(s.charAt(left) != s.charAt(right)){
                    break odd;
                }
            }
            //判断是否大于当前已记录的长度
            //这里(right - left)比实际长度多1，为了方便后面使用String.substring(beginIndex, endIndex)
            //即用数学的区间表示: [start, end),左边界元素包括，右边界元素不包括
            if(Lol < right - left){ 
            	Lol = right - left;
                start = left + 1;
                end = right; //endIndx为结束位置
            }
            
            //最长字串长度为偶数的情况
            left = i;
            right = i + 1;
            even:for( ; left >= 0 && right < len; left--, right++){
                if(s.charAt(left) != s.charAt(right)){
                    break even;
                }
            }
            //比较
            if(Lol < right - left){
                Lol = right - left;
                start = left + 1;
                end = right;
            }
        }
        return s.substring(start, end);
    }
}
```
