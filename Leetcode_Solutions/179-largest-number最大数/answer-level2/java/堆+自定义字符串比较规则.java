### 解题思路
这个题的关键就是怎么比较字符串的“大小”
假设字符串a和b，长度分别为m和n

1. 若m = n 直接调用compareTo
2. 若m > n 则截取a的前n个字符与b比较，若不相等则返回compareTo比较的结果，若相等则选取a剩下的字符串（a.subString(n)）与b进行比较，循环1，2步骤即可。


### 代码

```java
class Solution {
    public String largestNumber(int[] nums) {
        if (nums.length == 0)
            return "";
        //构建一个大顶堆
        PriorityQueue<String> pq = new PriorityQueue<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return myCompare(o1,o2);
            }
        });
        for (int num : nums) {
            pq.add(num + "");
        }
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()){
            sb.append(pq.remove());
        }
        String res = sb.toString();
        if (res.charAt(0) == '0')
            return "0";
        return res;
    }

    private int myCompare(String str1, String str2){
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 == len2)
            return str2.compareTo(str1);
        else if (len1 < len2){
            String pre = str2.substring(0, len1);
            int k = pre.compareTo(str1);
            if (k > 0)
                return 1;
            else if (k < 0)
                return -1;
            else {
                String suffix = str2.substring(len1);
                return myCompare(str1,suffix);
            }
        }
        else {
            String pre = str1.substring(0, len2);
            int k = str2.compareTo(pre);
            if (k > 0)
                return 1;
            else if (k < 0)
                return -1;
            else {
                String suffix = str1.substring(len2);
                return myCompare(suffix,str2);
            }
        }
    }
}
```