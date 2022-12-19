使用ASCII值标记法：因为ASCII只有128个，不管字符串有多长，数组的大小都会很小
第一次循环：用数组存字符出现的次数
第二次循环：减去出现的次数
第三次循环：检查数组的值是否为0

public boolean check(String s1, String s2) {
        if(s1.length()!=s2.length()){
            return false;
        }else{
            int[] temp = new int[256];
            for (int i = 0; i <s1.length(); i++) {
                char c = s1.charAt(i);
                if(temp[c]==0){
                    temp[c]=1;
                }else{
                    temp[c]=temp[c]+1;
                }
            }
            for (int i = 0; i <s2.length(); i++) {
                char c = s2.charAt(i);
                if(temp[c]==0){
                    return false;
                }else{
                    temp[c]=temp[c]-1;
                }
            }
            for (int i = 0; i < temp.length; i++) {
                if(temp[i]!=0){
                    return false;
                }
            }
            return true;
        }
    }