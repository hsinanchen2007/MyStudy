```
typedef struct
{
  int x;
  int y;
}Point;

typedef struct
{
  Point left_bot;
  Point right_top;
}Rec;

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){

  Rec recOne, recTwo;
  assert(sizeof(Rec) == (sizeof(int) * rec1Size));
  memcpy(&recOne, rec1, sizeof(Rec));
  memcpy(&recTwo, rec2, sizeof(Rec));

  // 先分开左右，再进行讨论
  Rec *left_rec, *right_rec;
  if(recOne.left_bot.x <= recTwo.left_bot.x)
  {
    left_rec = &recOne;
    right_rec = &recTwo;
  }
  else
  {
    left_rec = &recTwo;
    right_rec = &recOne;
  }

  if( (left_rec->right_top.x <= right_rec->left_bot.x) || // 左右无重叠
      (left_rec->left_bot.y >= right_rec->right_top.y) || // 左下大于右上，无重叠
      (left_rec->right_top.y <= right_rec->left_bot.y) )  // 左上小于右下，无重叠
  return 0;

  return 1;
}
```
