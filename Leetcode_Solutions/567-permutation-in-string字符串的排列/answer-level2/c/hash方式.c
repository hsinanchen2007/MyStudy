
int isInclude(int *nums1, int *nums2)
{
    int i;
    for (i = 0; i < 26; i++) {
        if (nums1[i] != nums2[i]) {
            return 0;
        }
    }
    return 1;
}
bool checkInclusion(char * s1, char * s2){
    int isNull = (s1 == NULL || s2 == NULL);
    int len1, len2, i, index;
    int nums1[26] = {0};
    int nums2[26] = {0};
    if (isNull) {
        return false;
    }
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }
    for (i = 0; i < len1; i++) {
        index = s1[i] - 'a';
        nums1[index]++;
        index = s2[i] - 'a';
        nums2[index]++;        
    }
    for (i = 0; i <=  len2 - len1; i++) { 
        if (isInclude(nums1,nums2)) {
            return true;
        }
        index = s2[i] - 'a';
        nums2[index]--;        
        if (i + len1 < len2) {
            index = s2[i+len1] - 'a';
            nums2[index]++;   
        }
    }
    return false;
}