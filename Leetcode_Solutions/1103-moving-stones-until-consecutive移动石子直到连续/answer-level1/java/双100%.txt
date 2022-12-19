class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] arr = {a,b,c};
        int[] arr1 = new int[2];
        Arrays.sort(arr);//排序
        int x = arr[0];
        int y = arr[1];
        int z = arr[2];
        arr1[1] =z-x-2;
        if (z-x == 2){//连在一起
            arr1[0] = 0;
        }else if (z-y == 1 || y-x == 1 || z-y ==2 || y -x ==2){//有一对连在一起或者有         一对中间只有一个位置
            arr1[0] = 1;
        }else {//其他情况
            arr1[0] = 2;
        }
        return arr1;
}
}