**  这个原来有人写过，找不到了，我再写一次。

  只使用一个hash和一个needMatch就可以。在这里我用数组nums:字符ascii->需要匹配的数目代替hash；needMatch表示还有几种字符没有匹配，如果为0，找到一个结果。

  刚开始用p初始化nums，接下来使用滑动窗口扫描s，如果right扫过，这个字符匹配了，所以对应的nums--；left扫过,nums++。

  对于在s里面不在p里面的字符，如果碰到，进入窗口即right扫过，离开窗口即left扫过，对应的nums一直是<=0；而在p里面的字符可能><=0。

  在right扫过的时候，即进入，如果是只差一个字符，进入了以后会变成0，这个时候needMatch--；left扫过的时候，即离开，如果正好是原来匹配的上字符离开，则会变成1，needMatch++。**

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> list = new ArrayList<>();
        if(s==null || s.length()<p.length())  return list;
        int m = s.length();
        int n = p.length();
        int[]nums = new int[256];//需要匹配的某种字符的数目
        int left = 0;
        int right = 0;
        int needMatch = 0;//需要匹配的字符种数
        char []cp = p.toCharArray();
        char []cs = s.toCharArray();
        for(char c:cp)
        {
            if(nums[c]==0)
                needMatch++;
            nums[c]++;
        }

        //考虑窗口[left,right)，先考虑第一个窗口
        while(right<n)
        {
            
            nums[cs[right]]--;
            if(nums[cs[right]]==0)
                needMatch--;
            right++;
                       
        }

        if(needMatch==0)   list.add(0);



        //对于后面的窗口，left移动一次，right移动一次算一个新的窗口
        while(right<m)
        {
            //p中没有出现的字符，right扫过（进入窗口）的时候是--，所以小于0，如果left又扫过（离开窗口），该字符++，如果进入的比离开的多，那么还是小于0；否则等于0。
            //p中出现的字符，可能会><=0，如果在上一个窗口的时候为0（即正好匹配），那么从窗口出来的时候会加1
            nums[cs[left]]++;
            if(nums[cs[left]]==1)  needMatch++; 
            



            //--以后为0，说明上一个窗口剩一个没有匹配，现在正好匹配，这个元素不需要匹配了，needMatch--
            nums[cs[right]]--;
            if(nums[cs[right]]==0)  needMatch--;


            left++;
            right++;
            if(needMatch==0)  list.add(left);


        }



        return list;

    }
}
```
