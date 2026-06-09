![image.png](https://pic.leetcode-cn.com/d40abee101f2b1df5f34465581d487967b57a860f7ad286f64a428f48e82725a-image.png)

执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.6 MB, 在所有 Java 提交中击败了100.00%的用户
```
class Solution {
    public int maxNumberOfBalloons(String text) {
        int ans = 10000;String began = "balloon";
        int [] arr = new int [26];
        char [] textCharArr = text.toCharArray();
        for (int i = 0; i < textCharArr.length; i++){
            arr[textCharArr[i]-'a']++;
        }
        arr['l' - 'a'] = arr['l' - 'a']/2;//因为气球单词中l为两个，因此除2减半
        arr['o' - 'a'] = arr['o' - 'a']/2; 因为气球单词中o为两个，因此除2减半
        int [] arrNew = new int [7];
        for (int i = 0; i < arrNew.length; i++){
            arrNew[i] = arr[began.charAt(i) - 'a'];
        }
          
        for (int i = 0; i < arrNew.length; i++){
            ans = Math.min(ans,arrNew[i]);
        }
        return ans;
    }
}
```
