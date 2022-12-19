执行用时 :5 ms, 在所有 Java 提交中击败了75.43%的用户
内存消耗 :35.5 MB, 在所有 Java 提交中击败了82.60%的用户
```
class Solution {
    public String countAndSay(int n) {
        if (n==1)return "1";
        
        String s0 = "11";//排除1的特殊时刻，从2开始。
        StringBuffer s = new StringBuffer();//利用统计每一个k的报数序列
        int counts = 0;//查找连续相同的字符个数
        int k = 1;//1-n一步一步推出每一层对应的报数序列
        
        while (n-1 > k){
            for (int i = 0; i < s0.length(); ){//遍历当前报数序列
                char c = s0.charAt(i);
                while (c == s0.charAt(i)) {//统计连续相等个数
			        counts++;
			        i++;
			        if (i == s0.length())break;//防止越界
			    }
                s.append(counts + "" + s0.charAt(i-1));//把相同的变成个数+数字
                counts = 0; //重置计数变量
        }
           s0 = s.toString();//将s
           s.delete(0,s.length());//重置s
            k++;
               
    }
        return s0;
    }
}
```
