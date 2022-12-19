### 代码

```java
class Solution {
    public int compress(char[] chars) {
        int i = 0; //index of the uncompressed array
        int j = 0; //index of the compressed array
        int count = 0; //count of the repeated characters
        
        if(chars.length == 1){
            return 1;
        }
        
        for(char curr = chars[0]; i < chars.length; ){
            while(i < chars.length && chars[i] == curr){
                count++;
                i++;
            }
            if(count == 1){
                j++;
                if(i < chars.length){
                    chars[j] = chars[i];
                    curr = chars[j];
                }
                
            }
            else if(count > 1 && count < 10){
                chars[j + 1] = (char)('0' + count);
                j += 2;
                if(i < chars.length){
                    chars[j] = chars[i];
                    curr = chars[j];
                }

            }
            else if(count >= 10 && count < 100){
                chars[j + 2] = (char)((count % 10) + '0');
                chars[j + 1] = (char)(((count/10) % 10) + '0');
                j += 3;
                if(i < chars.length){
                    chars[j] = chars[i];
                    curr = chars[j];
                }
            }
            else if(count >= 100 && count < 1000){
                chars[j + 3] = (char)((count % 10) + '0');
                chars[j + 2] = (char)(((count/10) % 10) + '0');
                chars[j + 1] = (char)(((count/100) % 10) + '0');
                j += 4;
                if(i < chars.length){
                    chars[j] = chars[i];
                    curr = chars[j];
                }
            }
            else if(count == 1000){
                chars[j + 1] = 1;
                chars[j + 2] = 0;
                chars[j + 3] = 0;
                chars[j + 4] = 0;
                j += 5;
            }
            count = 0;
        }
        
        return j;
    }
}
```