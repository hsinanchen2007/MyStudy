执行用时 :1 ms, 在所有 Java 提交中击败了99.88%的用户
内存消耗 :35.9 MB, 在所有 Java 提交中击败了74.17%的用户

先初始化一个对照表 如下
```
String[] mapKey ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//对应表
```
获取 依据当前指针获取
```
int index = 0;//定义初始游标
String key = mapKey[digits.charAt(index)-'2'];//'0','1' 无按键直接跳过
```

设好递归最后一层的代码与达到条件
```
 for (int i = 0; i < key.length(); i++) {
            nStr = lastStr+key.charAt(i);
            if (index>=digits.length()){//底层逻辑
                result.add(nStr);//递归底层结束
            }
        }
```

然后完整整合后 如下

```
class Solution {
    String[] mapKey ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//对应表
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits==null||digits.isEmpty()) return result;
        int index = 0;
        deal(result,digits,"",index);
        return result;
    }

    private List<String> deal(List<String> result,String digits,String lastStr,int index){
//        List<String> result = new ArrayList<>();
        if (index>=digits.length()) return result;
        String key = mapKey[digits.charAt(index)-'2'];//'0','1' 无按键直接跳过
        index++;
        String nStr;
        for (int i = 0; i < key.length(); i++) {
            nStr = lastStr+key.charAt(i);
            if (index>=digits.length()){//递归最后一层判断条件
                result.add(nStr);//递归底层结束
            }else {
                deal(result,digits,nStr,index);//递归处理
            }
        }

        return result;
    }
}
```
