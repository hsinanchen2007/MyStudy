这道题我是按照56题合并区间的思路来写的

首先将dict中的字符串 在s的位置给存进list里 比如说字符串s为aabcde dict是["abc","bcd"] 就将(1,3),(2,4)存进List里

然后就是合并区间, 当下一个int[0]<right，就要更改right，可以参考一下第56题
需要有一个s的index，因为s有的部分不是在bold标签里，就要将s.substring(index, left)存进stringbuilder里，
循环的判断条件是list.get(i)[0] - 1 <= right，因为如果字符串s为abcde dict是["abc","de"]这种情况应该返回<b>abcde</b>
此时d的index是3, c的index是2 所以要-1去判断
然后将substring存进stringbuilder里
index=right+1 指向了下一个开始的位置

最后需要判断一下是否index到达了s.length()
如果未到达 还需要将剩余部分加进stringbuilder里
```
class Solution {
    public String addBoldTag(String s, String[] dict) {
        if(dict.length == 0)
            return s;
        
        List<int[]> list = new ArrayList<>();
        for(int i = 0; i < s.length(); i++)
        {
            for(String dic: dict)
            {
                if(s.startsWith(dic, i))
                {
                    int[] temp = new int[]{i, i + dic.length() - 1};
                    list.add(temp);
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int index = 0;
        while(i < list.size())
        {
            int left = list.get(i)[0];
            int right = list.get(i)[1];
            sb.append(s.substring(index, left));
            while(i < list.size() && list.get(i)[0] - 1 <= right)
            {
                right = Math.max(right, list.get(i)[1]);
                i++;
            }
            sb.append("<b>" + s.substring(left, right + 1) + "</b>");
            index = right + 1;
        }
        if(index <= s.length() - 1)
            sb.append(s.substring(index, s.length()));
        return sb.toString();
    }
}
```
