
        class Solution {
        public boolean isPalindrome(int x) {
            String xx = Integer.toString(x);//先将数组转换成字符串。
            if(xx.length()<1||xx==null) return false;
            //接下来的三行是主要的步骤。
                //1.从两头开始比较数字是否一样，如果一样的话就像中间靠拢，如果不一样返回false。
                //2.当左数或者右数任意一个过了中点那么就返回true.
            int left = 0;
            int right = xx.length()-1;
            while(left >-1  && right<xx.length() &&xx.charAt(left)==xx.charAt(right)){
                    left++;
                    right--;
                    if(left>xx.length()/2) return true;
            }
        return false;
        }
    }