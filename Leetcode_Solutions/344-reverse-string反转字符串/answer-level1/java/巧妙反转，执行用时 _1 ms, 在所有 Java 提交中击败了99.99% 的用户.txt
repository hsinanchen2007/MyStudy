public class ReverseString {
    public void reverseString(char[] s) {
        int len = s.length;
        if (len == 0){return ;}
        int lastIndex = len - 1;
        for (int i = 0; i < len>>1; i++) {
            swap(s,i,lastIndex--);
        }
    }
    public void swap(char[] chars,int i ,int j){
        char temp = chars[i];
        chars[i]  = chars[j];
        chars[j] = temp;
    }

    public static void main(String []args){
        char[] chars={'h','e','l','l','o'};
        new ReverseString().reverseString(chars);
        System.out.println(Arrays.toString(chars));
    }

}