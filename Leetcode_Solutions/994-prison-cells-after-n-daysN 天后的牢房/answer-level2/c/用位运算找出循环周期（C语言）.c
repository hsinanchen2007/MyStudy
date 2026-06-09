/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef unsigned char UINT8;

/* 数字数组转Bit */
UINT8 ConvertIntToBits(int* cells, int cellsSize)
{
    UINT8 tmp = 0;
    for (int i = 0; i < cellsSize; i++) {        
        tmp |= (cells[i] << (cellsSize - i - 1));
    }
    return tmp;
}

/* Bit转数字数组 */
void ConvertBitsToInt(int* res, int cellsSize, UINT8 bits)
{
    for (int i = 0; i < cellsSize; i++) {                
        res[cellsSize - i - 1] = (bits >> i) & 1; 
    }
    return;
}

/* 用Bit计算下一次结果 */
UINT8 BitsMove(UINT8 bits)
{
    UINT8 tmp = 0;
    UINT8 left = bits << 1;
    UINT8 right = bits >> 1;
    
    tmp = ~(left ^ right);
    
    /* 首尾置0 */
    tmp &= 0x7F;
    tmp &= 0xFE;

    return tmp;
}

/* 计算循环周期后剩下的几天 */
UINT8 ProcCircle(UINT8 bits, int N, int i)
{
    UINT8 tmp = bits;
    
    int m = (N - 1) % i;
      
    for (i = 1; i <= m; i++) {
        tmp = BitsMove(tmp);      
    }
    
    return tmp;
}

int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    /* 数字数组转Bit */
	UINT8 bits = ConvertIntToBits(cells, cellsSize);
    
    *returnSize = cellsSize;
    int *res = (int *)calloc(cellsSize, sizeof(int));
    
	/* 先计算第一次结果 */
    bits = BitsMove(bits);    
    UINT8 bitsBase = bits;
    /* 首尾置0 */
    bitsBase &= 0x7F;
    bitsBase &= 0xFE;
    
	/* 再找出循环周期 */
    int i = 0;
    for (i = 2; i <= N; i++) {
        bits = BitsMove(bits);
        if (bitsBase == bits) {
            bits = ProcCircle(bits, N, i - 1);
            ConvertBitsToInt(res, cellsSize, bits);
            return res;
        }   
    }
    
	/* Bit转数字数组 */
    ConvertBitsToInt(res, cellsSize, bits);
    return res;    
}