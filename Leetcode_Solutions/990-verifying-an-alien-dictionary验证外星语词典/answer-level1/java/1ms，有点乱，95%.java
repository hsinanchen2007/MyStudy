![image.png](https://pic.leetcode-cn.com/a920f70e31101e6347472f9e973dd1cbacf9e96adc4857610e5e132294dc47c3-image.png)

```
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
            //将外星文转化为字符数组
        char [] arr = order.toCharArray();
            //遍历待检验的字符串数组
        for (int i = 0; i < words.length - 1; i++){
            //相邻两个字符串单独比较
            String one = words[i];
            String two = words[i+1];
            //如果前一个单词包含后一整个单词，一错全错，返回false
            if(one.contains(two))return false;
            //传入相邻的字符串，以及外星文字符数组
            //调用写的compare比较结果two小于one，返回false
            if(!compare(one,two,arr))return false;
            
       }
            //否则全部满足返回true
        return true;
    }
    
        //写的compare方法，作用是比较两个字符串的大小
    public boolean compare(String one,String two,char [] arr){
        int flag = 0;
        //遍历两个字符串中更短的字符串，去对比两个字符串中每一位字符
        for (int i = 0; i < Math.min(one.length(),two.length()); i++){
            //比较字符，要么大于，要么小于，要么等于，分别返回1，-1，0
            //这里的isOk是比较两个字符串中的两个字符，在arr字符串中的角标大小
            flag = isOk(one.charAt(i),two.charAt(i),arr);
            if(flag == 1){
                //代表two比one大，可以直接返回true
                return true;
            }else if (flag == -1){
                //代表one比two小，返回false
                return false;
            }
        }
        //遍历了这两个字符串完了都没出现大于小于情况，那就是相等或者包含，返回true
        return true;                                                                                                     
    }
    
    //比较两个字符的大小（按照arr的字典大小）
    public int isOk(char one,char two,char [] arr){
        int p1 = 0;int p2 = 0;int flag = 0;
        //这个简单，直接遍历就行了，找p1，p2，比较大小，返回flag就行
        for (int i = 0; i < arr.length; i++){
            if (one == arr[i]){
                p1 = i;
                break;
            }
        }
        for (int i = 0; i < arr.length; i++){
            if (two == arr[i]){
                p2 = i;
                break;
            }
        }
        
        if (p2 > p1){
            flag = 1;
        }else if (p2 < p1){
            flag = -1;
        }else{
            flag = 0;
        }
        
        return flag;
    }
}
```
