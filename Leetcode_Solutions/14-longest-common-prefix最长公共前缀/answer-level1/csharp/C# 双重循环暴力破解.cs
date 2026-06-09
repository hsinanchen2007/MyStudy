checked检测索引超出，双重循环暴力破解，内存占用高，耗时长。
![image.png](https://pic.leetcode-cn.com/cd81d0af4c44c2415b4986e4589268024c8cfd0e92dec704558b55facb04499d-image.png)

```
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        string val=string.Empty;
        try{
            
            checked{
                for(int i=0;i<strs[0].Length;i++){
                    bool isIdentical=true;
                    for(int j=1;j<strs.Length;j++){
                        if(strs[j].Substring(0,i+1)!=strs[0].Substring(0,i+1)){
                            isIdentical=false;
                            break;
                        }
                    }
                    if(isIdentical){
                        val=strs[0].Substring(0,i+1);
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
            return val;
        }
        catch{
            return val;
        }
    }
}
```
