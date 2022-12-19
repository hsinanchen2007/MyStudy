```
int minArea(char** image, int imageSize, int* imageColSize, int x, int y)
{
    if ((image == NULL) || (imageSize == 0) || (imageColSize == NULL) || (*imageColSize == 0)) {
        return 0;
    }

    int *imageXProjection = (int *)malloc((*imageColSize) * sizeof(int));
    memset(imageXProjection, 0, (*imageColSize) * sizeof(int));
    int *imageYProjection = (int *)malloc((imageSize) * sizeof(int));
    memset(imageYProjection, 0, (imageSize) * sizeof(int));

    int i;
    int j;
    for (i = 0; i < *imageColSize; i++) {
        for (j = 0; j < imageSize; j++) {
            imageXProjection[i] |= image[j][i] - '0';
        }
        //printf("imageXProjection[%d]: %d\n", i, imageXProjection[i]);
    }
    for (i = 0; i < imageSize; i++) {
        for (j = 0; j < *imageColSize; j++) {
            imageYProjection[i] |= image[i][j] - '0';
        }
        //printf("imageYProjection[%d]: %d\n", i, imageYProjection[i]);
    }

    int xLen = 0;
    for (i = 0; i < *imageColSize; i++) {
        if (imageXProjection[i] == 1) {
            xLen = i;
            break;
        }
    }
    for (i = *imageColSize - 1; i >= 0; i--) {
        if (imageXProjection[i] == 1) {
            xLen = i - xLen + 1;
            break;
        }
    }
    //printf("xLen: %d\n", xLen);

    int yLen = 0;
    
    for (i = 0; i < imageSize; i++) {
        if (imageYProjection[i] == 1) {
            yLen = i;
            break;
        }
    }
    for (i = imageSize - 1; i >= 0; i--) {
        if (imageYProjection[i] == 1) {
            yLen = i - yLen + 1;
            break;
        }
    }

    //printf("yLen: %d\n", yLen);
    int returnArea = xLen * yLen;
    //printf("returnArea: %d\n", returnArea);

    return returnArea;
}
```
