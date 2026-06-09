### 解题思路
89.17%

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int [] [] arr = new int[123][2]; //使用一个二维数组记录chars中每一个字母出现的次数，97-122对应a-z。这里避免后面不断减97，牺牲空间换取时间，前97个数组单元无用。
        for (char ch: chars.toCharArray()){
            arr[ch][0]++;//初始化
        }
        int sum =0;//计数：掌握的所有单词的 长度之和
        for (String word : words){
            for (int i=97;i<123;i++){//从arr导入过来
                arr[i][1]=arr[i][0];
            }
            boolean match =true;//是否匹配
            for (char ch:word.toCharArray()){//遍历每一个Word的字母
                if(arr[ch][1]--==0){//每次使用该字母作为下标，给数组减1，减之前<=0即表示字母已经被用完了，不可能匹配
                    match = false;
                    break;
                }
            }
            if (match) sum+=word.length();//加上Word长度
        }
        return sum;
    }
}
```