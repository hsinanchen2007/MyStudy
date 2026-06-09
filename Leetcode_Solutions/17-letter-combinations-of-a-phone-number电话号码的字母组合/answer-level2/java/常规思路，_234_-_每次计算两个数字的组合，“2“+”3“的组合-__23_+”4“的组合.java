### 解题思路
感觉是最常规的思路了

### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits==null || digits.length()==0){
            return new ArrayList<String>();
        }
        int len = digits.length();
        List<String> mapx = getCharMap(digits.charAt(0));
        for (int i = 1; i < len; i++) {
//获取当前数字对应的List<String>
            List<String> mapi = getCharMap(digits.charAt(i));
//将当前数字对应的List<String>与之前的所有数字的List<String>进行组合，还是返回一个List<String>
            mapx = getCom(mapx,mapi);
        }
        return mapx;
    }
    //将两个List<String>进行组合，返回一个List<String>供给下次组合
    private List<String> getCom(List<String> l1, List<String> l2) {
        ArrayList<String> s = new ArrayList<String>();
        for (int i = 0; i < l1.size(); i++) {
            for (int j = 0; j < l2.size(); j++) {
                s.add(l1.get(i)+l2.get(j));
            }
        }
        return s;
    }

    //获取数字对应的List<String>
    private List<String> getCharMap(char c) {
        switch (c){
            case '2':
                return new ArrayList<String>(Arrays.asList("a","b","c"));
            case '3':
                return new ArrayList<String>(Arrays.asList("d","e","f"));
            case '4':
                return new ArrayList<String>(Arrays.asList("g","h","i"));
            case '5':
                return new ArrayList<String>(Arrays.asList("j","k","l"));
            case '6':
                return new ArrayList<String>(Arrays.asList("m","n","o"));
            case '7':
                return new ArrayList<String>(Arrays.asList("p","q","r","s"));
            case '8':
                return new ArrayList<String>(Arrays.asList("t","u","v"));
            case '9':
                return new ArrayList<String>(Arrays.asList("w","x","y","z"));
            default:
                return null;
        }
    }
}
```