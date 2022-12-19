```
bool CheckParam(int *data, int dataSize)
{
    if (!data || dataSize < 1) {
        return false;
    }
    return true;
}

bool CheckOne(int *data)
{
    if ((data[0] >> 7) % 2 == 0) {
        printf("CheckOne 1\n");
        return true;
    }
    printf("CheckOne 0\n");
    return false;
}

bool CheckTwo(int *data)
{
    if (((data[0] >> 7) % 2 == 1) && ((data[0] >> 6) % 2 == 1) &&
        ((data[0] >> 5) % 2 == 0) && ((data[1] >> 7) % 2 == 1) &&
        ((data[1] >> 6) % 2 == 0)) {
        printf("CheckTwo 1\n");
        return true;
    }
    printf("CheckTwo 0\n");
    return false;
}

bool CheckThr(int *data)
{
    if ((data[0] >> 7) % 2 == 1 && (data[0] >> 6) % 2 == 1 &&
        (data[0] >> 5) % 2 == 1 && (data[0] >> 4) % 2 == 0 &&
        (data[1] >> 7) % 2 == 1 && (data[1] >> 6) % 2 == 0 &&
        (data[2] >> 7) % 2 == 1 && (data[2] >> 6) % 2 == 0) {
        printf("CheckThr 1\n");
        return true;
    }
    printf("CheckThr 0\n");
    return false;
}

bool CheckFou(int *data)
{
    if ((data[0] >> 7) % 2 == 1 && (data[0] >> 6) % 2 == 1 &&
        (data[0] >> 5) % 2 == 1 && (data[0] >> 4) % 2 == 1 &&
        (data[0] >> 3) % 2 == 0 && (data[1] >> 7) % 2 == 1 &&
        (data[1] >> 6) % 2 == 0 && (data[2] >> 7) % 2 == 1 &&
        (data[2] >> 6) % 2 == 0 && (data[3] >> 7) % 2 == 1 &&
        (data[3] >> 6) % 2 == 0) {
        printf("CheckFou 1\n");
        return true;
    }
    printf("CheckFou 0\n");
    return false;
}

bool validUtf8(int *data, int dataSize)
{
    int last = dataSize;
    int *p = data;

    if (!CheckParam(data, dataSize)) {
        return false;
    }
    while (true) {
        bool flag = false;
        if ((last >= 1) && CheckOne(p)) {
            last -= 1;
            p += 1;
            flag = true;
            printf("[1]%d\n", last);
        }
        if ((last >= 2) && CheckTwo(p)) {
            last -= 2;
            p += 2;
            flag = true;
            printf("[2]%d\n", last);
        }
        if ((last >= 3) && CheckThr(p)) {
            last -= 3;
            p += 3;
            flag = true;
            printf("[3]%d\n", last);
        }
        if ((last >= 4) && CheckFou(p)) {
            last -= 4;
            p += 4;
            flag = true;
            printf("[4]%d\n", last);
        }
        if (!flag) {
            break;
        }
    }
    printf("[5]%d\n", last);
    if (last == 0) {
        return true;
    }
    return false;
}
```
