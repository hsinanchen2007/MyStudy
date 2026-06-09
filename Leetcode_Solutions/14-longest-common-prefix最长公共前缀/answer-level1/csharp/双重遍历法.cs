执行用时 : 116 ms, 在所有 csharp 提交中击败了96.01%的用户
内存消耗 : 23.4 MB, 在所有 csharp 提交中击败了11.69%的用户
```
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        //1、判断数组是否为空
        if(strs.Length == 0){
            return "";        
        }
        //2、取数组中第一个下标元素
        string first = strs[0];
        string joinStr = "";//记录公共部分
        //3、遍历第一个字符串
        for(int i = 0; i < first.Length;i++){
            //4、与其他字符串进行对比，前缀是否相同
            for(int j = 1;j < strs.Length; j++){
                //5、公共部分的长度不能大于其他任意一个字符串的长度
                if(joinStr.Length >= strs[j].Length){
                    return joinStr;
                }
                //6、比较相同位置的元素是否相同
                string temp = strs[j];
                if(temp[i] != first[i]){
                    return joinStr;
                }

            }
            //7、满足以上条件，将公共元素拼接到joinStr里
            joinStr += first[i];
        }
        return joinStr;
        
    }
}
```