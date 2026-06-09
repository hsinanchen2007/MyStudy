核心算法就是把字符串中“.“隔离的数字存到制定数组中进行保存，比较保存后的数组。
1.使用strtok获取隔离符”.”中的数字字符串。
2.使用atoi转换数字字符串为数字，保存到数组中。
核心算法如下所示：
void analysis_version(char *version, int point_num, int flag){
    int i;

    if (point_num == 0) {
        if (flag == 1) {
            nums1[0] = atoi(version);
        } else {
            nums2[0] = atoi(version);
        }
        return;
    }
    if (flag == 1) {
        nums1[0] = atoi(strtok(version, "."));
        for (i = 1; i <= point_num; i++) {
            nums1[i] = atoi(strtok(NULL, "."));
        }
    } else {
        nums2[0] = atoi(strtok(version, "."));
        for (i = 1; i <= point_num; i++) {
            nums2[i] = atoi(strtok(NULL, "."));
        }
    } 
    return;
}