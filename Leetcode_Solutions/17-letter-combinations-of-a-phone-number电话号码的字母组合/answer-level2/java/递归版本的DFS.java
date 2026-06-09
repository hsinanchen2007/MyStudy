一个递归版本的深度优先搜索的实现，Java代码
这个是两个月之前的版本，这个版本虽然可以成功AC，但是还存在一些问题：
首先是我采用了StringBuilder来代替String,试图通过这种方法来避免产生大量的小对象，但是由于这一句话的存在：
`combination_recursive(digit, index + 1, ans, new StringBuilder(temp.toString()).append(list[i]));`
我还是必须把StringBuilder转化为String，完美的避开了StringBuilder的优点，成功的达到了脱裤子放屁的效果。
emmmm，真是够了。

所以现在又提供了一个递归深度优先遍历的版本。使用char[] 数组实现了一个栈的功能，然后通过`new String(char[] value)`这个构造函数，直接生成最后的结果
避免了大量产生小对象，节约了空间，同时节约了时间。

新版本：
```java
public class Letter_Combinations_of_a_Phone_Number {
    static String[] numbers = {"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};

    public List<String> letterCombinations(String digits) {
        if(digits == null || digits.length() == 0){
            return new ArrayList<String>();
        }
        List<String> ans = new ArrayList<String>();
        // 基于 char 数组 构造一个手工栈
        char[] chars = new char[digits.length()];
        int chars_index = -1;

        dfs(0, chars, chars_index, digits, ans);
        return ans;
    }

    private void dfs(int cur_index, char[] chars, int chars_index, String digits, List<String> ans){
        // 递归的结束条件为：所有数字都已经被递归遍历过了，当前指向的数字超出了字符串，
        // 将栈转化为一个String，加入到结果List中，并返回。
        if(cur_index == digits.length()){
            ans.add(new String(chars));
            return;
        }
        int cur_num = digits.charAt(cur_index) - '0';
        if(cur_num <= 1){
            // 如果对应的数字是0或者1的话，直接跳过这个数字，进入下一层递归
            dfs(cur_index + 1, chars, chars_index, digits, ans);
        }else {
            for(int i = 0; i < numbers[cur_num].length(); i++){
                // 将这个数字对应的某一个字符入栈
                chars_index++;
                chars[chars_index] = numbers[cur_num].charAt(i);
                
                // 递归调用，同时将栈传入给递归函数
                dfs(cur_index + 1, chars, chars_index, digits, ans);
                
                // 递归调用完毕之后，将该字符出栈，
                // 为该数字对应的下一个字符入栈做准备
                chars[chars_index] = '\u0000';
                chars_index--;
            }
        }

        return;
    }
}
```



常规版：
```  java
class Solution {
    public static char[][] numbers = {
            {},                // 0
            {},                // 1
            {'a','b','c'},     // 2
            {'d','e','f'},     // 3
            {'g','h','i'},     // 4
            {'j','k','l'},     // 5
            {'m','n','o'},     // 6
            {'p','q','r','s'}, // 7
            {'t','u','v'},     // 8
            {'w','x','y','z'}, // 9
    };

    public List<String> letterCombinations(String digits) {
        ArrayList<String> ans = new ArrayList<>();
        if(digits == null || digits.length() == 0){
            return ans;
        }

        // 将digits字符串转换为int数组
        int[] digit  = new int[digits.length()];
        for(int i = 0; i < digits.length(); i++){
            digit[i] = digits.charAt(i) - '0';
        }
        
        // 调用DFS进行遍历
        combination_recursive(digit, 0, ans,new StringBuilder());
        return ans;
    }

    private void combination_recursive(int[] digit, int index, List<String> ans, StringBuilder temp){
        // 边界条件，
        // index超过数组长度，说明已经到达了最大深度，直接返回即可
        if(index == digit.length){
            ans.add(temp.toString());
            return;
        }
        // 获取这个数字对应的字符
        char[] list = numbers[digit[index]];
        // 进行深度优先搜索
        for(int i = 0; i < list.length; i++){
            combination_recursive(digit, index + 1, ans, new StringBuilder(temp.toString()).append(list[i]));
        }
    }
}
```