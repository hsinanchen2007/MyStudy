#define MAX_LEN    1024

void StrToInt(char *srcStr, int *dataBuf, int *dataLen)
{
    if (srcStr == NULL || dataBuf == NULL || dataLen == NULL) {
        return;
    }

    char tempStr[MAX_LEN] = { 0 };
    char *pStr = srcStr;
    int count = 0;

    dataBuf[count] = atoi(pStr);
    count++;

    while (*pStr != '\0') {
        if (*pStr == '.') {
            strcpy(tempStr, pStr + 1);
            dataBuf[count] = atoi(tempStr);
            count++;
        }
        pStr++;
    }

    *dataLen = count;
}

int compareVersion(char * version1, char * version2)
{
    int version1Data[MAX_LEN] = { 0 };
    int version2Data[MAX_LEN] = { 0 };
    int i;
    int version1DataLen;
    int version2DataLen;
    int max;

    StrToInt(version1, version1Data, &version1DataLen);
    StrToInt(version2, version2Data, &version2DataLen);

    max = version1DataLen >= version2DataLen ? version1DataLen : version2DataLen;

    for (i = 0; i < max; i++) {
        if (version1Data[i] > version2Data[i]) {
            return (1);
        }

        if (version1Data[i] < version2Data[i]) {
            return (-1);
        }
    }

    return (0);
}