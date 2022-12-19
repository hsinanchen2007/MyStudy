class Solution {
    public boolean buddyStrings(String A, String B) {
        char[] arrA = A.toCharArray();
        char[] arrB = B.toCharArray();
        if(arrA.length!=arrB.length){
            return false;
        }
        int[] tmp = new  int[2];
        int[] count = new int[26];
        int max = 0;
        int index = 0;
        for(int i=0;i<arrA.length;i++){
            if(arrA[i] != arrB[i]){
                if(index<2){
                    tmp[index++] = i; 
                }else{
                    return false;
                }
            }else{
                count[arrA[i]-'a'+1]++;
                max = max<count[arrA[i]-'a'+1]?count[arrA[i]-'a'+1]:max;
            }
        }

        if(index==2&&(arrA[tmp[0]]==arrB[tmp[1]]&&arrB[tmp[0]]==arrA[tmp[1]])){
            if(!(arrA[tmp[0]]==arrB[tmp[1]]&&arrB[tmp[0]]==arrA[tmp[1]])){
                return false;
            }
        }else if(index==0){
            if(max<2){
                return false;
            }
        }else{
            return false;
        }

        return true;
    }
}