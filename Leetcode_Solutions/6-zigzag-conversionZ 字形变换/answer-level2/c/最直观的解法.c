最直观的办法，求出矩阵的行数和列数，再把字符串按照Z字形的规则进行填充，最后再逐个遍历矩阵的元素拼装出结果。
char * convert(char * s, int numRows){
    if(numRows <=1)
    {
        return s;
    }

    int i,j,k;
    char *str =s;
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len+1));
    memset(res, '\0', len+1);
    int row = numRows;
    int quotient = len / (row + (row-2)); //商
    int remainder = len % (row + (row-2)); //余
    int col = (row-2+1) * quotient;  //列数
    if(remainder > 0)
    {
        col++;
        remainder -= row;
        if(remainder > 0)
        {
            col += remainder;
        }        
    }

    char **matrix = (char **)malloc(sizeof(char *) * row);
    for(i=0; i<row; i++)
    {
        matrix[i] = (char *)malloc(sizeof(char) * col);
    }

    for(j=0; j<col; j++)
    for(i=0; i<row; i++)
    {
        if((j%(numRows-1) == 0 || (i+j)%(numRows-1) == 0) && *str)
        {
            matrix[i][j] = *str;
            str++;
        }
        else
        {
            matrix[i][j] = ' ';
        }
    }

    k=0;
    for(i=0; i<row; i++)
    for(j=0; j<col; j++)
    {
        if(matrix[i][j] != ' ')
        {
            res[k] = matrix[i][j];
            k++;
        }
    }

    return res;
}