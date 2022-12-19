int maxArea(int* height, int heightSize){
    int p1 = 0;
    int p2 = heightSize - 1;
    int max = 0;
    int direction;
    int tmp;

    if (heightSize == 1) {
        return 0;
    }

    while (p1 < p2) {   
        tmp = (p2 - p1) * ((height[p1] > height[p2]) ? height[p2] : height[p1]);
        if (tmp > max) {
            max = tmp;
        }
        direction = ((height[p1] > height[p2])) ? 1 : 0;
        if (direction) {
            p2--;
        } else {
            p1++;
        }
    } 

    return max;
}