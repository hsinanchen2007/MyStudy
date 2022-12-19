class Solution {
    public int minArray(int[] numbers) {
        int temp = numbers[0];
        for (int a:numbers){
            if (a<temp){
                temp = a;
            }
        }
        return temp;
    }
}