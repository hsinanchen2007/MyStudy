双指针+ ASCII的比较 

```java
public boolean isPalindrome(String s) {
        boolean result = true;
        int left = 0 , right = s.length() - 1;
        while(left < s.length() - 1 && right > 0){
            int leftChar = s.charAt(left) | 32;
            int rightChar = s.charAt(right) | 32;
            if(!  ((leftChar >= 48 &&  leftChar <=57) || (leftChar >= 97 && leftChar <= 122) )){
                left++;
                continue;
            }
            if(!  ((rightChar >= 48 &&  rightChar <=57) || (rightChar >= 97 && rightChar <= 122) )){
                right--;
                continue;
            }

            if(leftChar  != rightChar){
                result = false;
                break;
            }else{
                left++;
                right--;
            }

        }
        return result;
    }

```
