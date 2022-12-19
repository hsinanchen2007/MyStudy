将两个字符串装配为二维数组，第一维存放字符，第二维存放状态，初始默认全部为F。
每次比较第一个数组的字符，若第二个数组有相同的，则把两个数组相对应的位置的状态改为T。
一旦出现不匹配的，立即返回false

`
class Solution {
    public static boolean CheckPermutation(String s1, String s2) {
        boolean flag = true;
        if(s1.length()!=s2.length()){
            return false;
        }
        int length = s1.length();
        char[][] str1 = new char[length][2];
        char[][] str2 = new char[length][2];
        for(int i=0;i<length;i++){
            str1[i][0] = s1.charAt(i);
            str1[i][1] = 'f';
            str2[i][0] = s2.charAt(i);
            str2[i][1] = 'f';
        }
        for(int i=0;i<length;i++){
            flag = false;
            for(int j=0;j<length;j++){
                if(str1[i][0] == str2[j][0] && str2[j][1] == 'f'){
                    str1[i][1] = 't';
                    str2[j][1] = 't';
                    flag = true;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        return flag;
    }
}
`