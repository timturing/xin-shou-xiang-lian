#include <stdio.h>
struct Student
{
    int sno; //学号
    int num; //刷题数量
};
int req[105]; //老师要求的题
Student stus[105];
int main()
{
    //读入
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    int m, k;
    scanf("%d", &m);
    scanf("%d", &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &stus[i].sno);
        stus[i].num = 0;
        int p;
        scanf("%d", &p);
        //后面p个题目是第i位同学刷的题
        // 枚举
        for (int j = 0; j < p; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            // tmp是某一道题
            for (int k = 0; k < n; k++)
            {
                if (tmp == req[k])
                {
                    stus[i].num++;
                }
            }
        }
    }

    // 排序
    for (int i = 0; i <= m - 2; i++)
    {
        for (int j = i + 1; j <= m - 1; j++)
        {
            // 比较规则
            if (stus[i].num < stus[j].num)
            {
                // 交换
                Student tmp;
                tmp = stus[i];
                stus[i] = stus[j];
                stus[j] = tmp;
            }
            if (stus[i].num == stus[j].num)
            {
                if (stus[i].sno > stus[j].sno)
                {
                    // 交换
                    Student tmp;
                    tmp = stus[i];
                    stus[i] = stus[j];
                    stus[j] = tmp;
                }
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < m; i++)
    {
        printf("%d %d\n", stus[i].sno, stus[i].num);
    }
#endif
    int w = 1; //当前排名到多少了
    // 输出第一个
    printf("%d ", stus[0].sno);
    for (int i = 1; i < m; i++)
    {
        if (stus[i].num == stus[i - 1].num)
        {
        }
        else
        {
            w++;
        }
        if (w <= k)
            printf("%d ", stus[i].sno);
    }
}