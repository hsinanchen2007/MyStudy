用正则表达式“\\.”把字符串截取成字符串数组,遍历字符串数组，取出每一项后边追加“[.]”直到最后一项不用追加
```
public static String defangIPaddr(String address) {
        StringBuffer sb = new StringBuffer();
        String [] arr = address.split("\\.");
        for(int i=0;i<arr.length;i++){
            if(i==arr.length-1){ //最后一项
                sb.append(arr[i]);
                break;  //后边循环体的代码不会执行
            }
            sb.append(arr[i]+"[.]");
        }
        return sb.toString();
    }
```

第二种：还可以用Java内置函数replaceAll("\\.","[.]");