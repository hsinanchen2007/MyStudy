int maxArea(int* height, int heightSize){
        int volume = 0;
        int begin, end;
        for (begin = 0; begin < heightSize; begin++) {
            for (end = begin; end < heightSize; end++) {
               int minHeight = height[begin] < height[end] ? height[begin] : height[end];
               int tmpVolume = minHeight * (end - begin);
              if (tmpVolume > volume) {
                   volume = tmpVolume;
                }
            }
        }

        return volume;
}