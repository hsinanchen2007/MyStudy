```
public class Demo038 {
    public static String countAndSay(int n) {
        StringBuffer sb = null;
        String str = "1";
        //长度为 1 时 直接返回
        if(n == 1){
            return str;
        }

        //构建 n 为 2 3 。。。 时的 外观数列
        for(int i = 1; i < n; i ++){
            sb = new StringBuffer("");
            int count = 1;
            //循环遍历外观数列 构建下一个 外观数列
            for(int j = 0;j < str.length();j++){
                //相邻的两个字符相等则令 cout ++
                if(j + 1 < str.length() && str.charAt(j) == str.charAt(j + 1)){
                    count ++;
                }else{
                    //若 两个字符不想等 则 构建 外观数列
                    sb.append(count).append(str.charAt(j));
                    count = 1;
                }
            }
            str = sb.toString();
        }

        return sb.toString();
    }


    public static void main(String[] args) {
        System.out.println(countAndSay(30));
    }


}

```
