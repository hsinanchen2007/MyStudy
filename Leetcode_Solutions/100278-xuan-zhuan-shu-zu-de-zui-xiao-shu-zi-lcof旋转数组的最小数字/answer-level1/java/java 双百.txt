class Solution {
    // public int minArray(int[] numbers) {
    //     int a = numbers[0];
    //     for(int i = 1; i< numbers.length; i ++){
    //         if(a - numbers[i] <= 0){
    //             continue;
    //         }
    //         a = numbers[i];           
    //     }
    //     return a;
    // }
    public static int minArray(int[] numbers) {
        int a = numbers[numbers.length - 1];
        for(int i = numbers.length - 1; i > 0; i --){
            if(a >  numbers[i - 1]){
                a = numbers[i - 1];
            }
        }
        return a;
    }
}