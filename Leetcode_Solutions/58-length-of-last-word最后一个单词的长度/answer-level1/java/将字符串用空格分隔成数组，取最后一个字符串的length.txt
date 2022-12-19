```
public int lengthOfLastWord(String s) {
        String[] split = s.split("\\ ");
        return split.length == 0 ? 0 : split[split.length - 1].length();//split数组的length可能为0
    }
```
