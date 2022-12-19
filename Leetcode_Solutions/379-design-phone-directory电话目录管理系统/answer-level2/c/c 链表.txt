typedef struct PhoneDirectory{
int tel_num;
int status; //the tel_number is used 1 or is 0;
struct PhoneDirectory *next;  
} PhoneDirectory;

/** Initialize your data structure here
@param maxNumbers - The maximum numbers that can be stored in the phone directory-> */

PhoneDirectory* phoneDirectoryCreate(int maxNumbers) {
int i;
PhoneDirectory* head;
PhoneDirectory *ntmp;
head = (PhoneDirectory *)malloc(sizeof(PhoneDirectory));
head->next = NULL;
for (i = 1; i < maxNumbers; i++) {
ntmp = (PhoneDirectory *)malloc(sizeof(PhoneDirectory));
ntmp->tel_num = maxNumbers - i;
ntmp->status = 0;
ntmp->next = head->next;
head->next = ntmp;
}

head->tel_num = 0;
head->status = 0; 

return head;
}

/** Provide a number which is not assigned to anyone->
@return - Return an available number-> Return -1 if none is available-> */
int phoneDirectoryGet(PhoneDirectory* obj) {
int p_num;
int flag = -1;
while (obj != NULL) {
if (obj->status == 0) {
p_num = obj->tel_num;
flag = 0;
obj->status = 1;
break;
}
obj = obj->next;
}
if (flag) {
return -1;
}

return p_num;
}

/** Check if a number is available or not-> */
bool phoneDirectoryCheck(PhoneDirectory* obj, int number) {
while (obj != NULL) {
if (obj->tel_num == number && obj->status == 0) {
return true;
}
obj = obj->next;
}

return false;
}

/** Recycle or release a number-> */
void phoneDirectoryRelease(PhoneDirectory* obj, int number) {
while (obj != NULL) {
if (obj->tel_num == number) {
obj->status = 0;
return;
}
obj = obj->next;
}
}

void phoneDirectoryFree(PhoneDirectory* obj) {
struct PhoneDirectory *tmp;
if (obj->next != NULL) {
tmp = obj;
obj = obj->next;
free(tmp);
}
}

void phoneDirectory(int maxNumbers)
{
PhoneDirectory* obj = phoneDirectoryCreate(maxNumbers);
# }