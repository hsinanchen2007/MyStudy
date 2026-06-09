### 解题思路
憨憨代码，虽然不是很好，但是应该挺好看懂，不管怎么样记录一下

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        String longestString = "";
        String current = "";
        int i =0,j = 0;
        int left = 0,right = 0;
        boolean isPalindrome = false;
        if(s.length()==1){
            return s;
        }
        while(j<n){
            isPalindrome = false;
            int theFirstLocation =0;
            if(current.length()> 0 && current.contains(String.valueOf(s.charAt(j)))){
                for(theFirstLocation = 0;theFirstLocation<current.length();theFirstLocation++){
                    if(s.charAt(j) == current.charAt(theFirstLocation))
                    {
                        left = theFirstLocation;
                        right = j;
                    while(left!=j){
                       if(s.charAt(left)== s.charAt(right)){
                        left++;
                        right--;
                       }else{
                        break;
                    }
                }
                 //如果p=j说明该段是回文的，那么i的位置就需要下降
               if(left==j){
                i = theFirstLocation;
                isPalindrome = true;
                break;
                }
                }

                }                             
            } 
            current+= String.valueOf(s.charAt(j));
            j++;
            
            if(isPalindrome){
                String ss = s.substring(i,j);//这是一个前开后闭区间
                if(ss.length()>longestString.length()){
                longestString = ss;
                }
            }                   
        }
        if(longestString == "" && s.length()>=2){
            longestString = s.substring(0,1);
        }
        return longestString;
    }

    }
```