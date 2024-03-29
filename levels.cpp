void initializeArray(int array[15][15])
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = 0;  
}

void l1_5(int array[15][15])
{
    array[1][1] = 1;
    array[1][3] = 1;
    array[3][0] = 1;
    array[3][4] = 1;
    array[4][1] = 1;
    array[4][2] = 1;
    array[4][3] = 1;
}

void l2_5(int array[15][15])
{
    for (int i = 0; i < 5; i++) {
        array[0][i] = 1;
        array[4][i] = 1; }

    for (int i = 1; i < 4; i++) {
        array[i][0] = 1;
        array[i][4] = 1; }

    array[2][2] = 1;
}

void l3_5(int array[15][15])
{
    for (int i = 0; i < 5; i++) {
        array[i][0] = 1;
        array[i][4] = 1; }
    
    for (int i = 1; i < 4; i++) {
        array[2][i] = 1;
        array[4][i] = 1; }
    
    array[1][2] = 1;
    array[3][2] = 1;
}

void l4_5(int array[15][15])
{
    array[0][2] = 1;

    for (int i = 1; i < 4; i++)
        array[2][i] = 1;

    for (int i = 0; i < 5; i++)
        array[4][i] = 1;
}

void l5_5(int array[15][15])
{
    for (int i = 0; i < 5; i++) {
        array[0][i] = 1;
        array[2][i] = 1;
        array[4][i] = 1; }
    
    array[1][0] = 1;
    array[3][4] = 1;
}

void l6_5(int array[15][15])
{
    for (int i = 2; i < 5; i++) {
        array[0][i] = 1;
        array[i][4] = 1; }
    
    for (int i = 0; i < 3; i++) {
        array[i][0] = 1;
        array[4][i] = 1; }
    
    array[2][2] = 1;
}

void l7_5(int array[15][15])
{
    for (int i = 0; i < 5; i++)
    {
        array[i][i] = 1;
        array[i][0] = 1;
        array[i][4] = 1;
    }
}

void l8_5(int array[15][15])
{
    for (int i = 0; i < 4; i++)
        array[i][2] = 1;
    
    for (int i = 0; i < 5; i++)
        array[4][i] = 1;
    
    array[0][0] = 1;
    array[0][4] = 1;
    array[4][2] = 0;
    
}

void l9_5(int array[15][15])
{
    for (int i = 0; i < 5; i = i + 2)
        array[0][i] = 1;

    for (int i = 1; i < 4; i++) {
        array[i][1] = 1;
        array[i][3] = 1; }
    
    for (int i = 0; i < 5; i++)
        array[4][i] = 1;
    
    array[3][2] = 1;
}

void l10_5(int array[15][15])
{
     for (int i = 0; i < 5; i++) {
        array[0][i] = 1;
        array[2][i] = 1;
        array[4][i] = 1; }
    
    for (int i = 0; i < 5; i = i + 2)
        array[i][1] = 0;
    
    array[1][1] = 1;
    array[3][1] = 1;
    array[2][4] = 0;
}


void l1_10(int array[15][15])
{
    for (int i = 2; i < 8; i++)
    {
        array[0][i] = 1;
        array[9][i] = 1;
        array[i][0] = 1;
        array[i][9] = 1;
    }

    array[1][1] = 1;
    array[1][8] = 1;
    array[8][1] = 1;
    array[8][8] = 1;
    array[3][3] = 1;
    array[3][6] = 1;
    array[6][2] = 1;
    array[6][7] = 1;

    for (int i = 3; i < 7; i++)
        array[7][i] = 1;
    
}

void l2_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l3_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l4_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l5_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l6_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l7_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                          {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l8_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l9_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l10_10(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}


void l1_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1},
                          {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                          {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
                          {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                          {0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                          {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                          {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
                          {0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0},
                          {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
                          {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
                          {1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                          {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l2_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                          {0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                          {0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                          {0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                          {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l3_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l4_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                          {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                          {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l5_15(int array[15][15])
{
    int values[15][15] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1},
                          {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                          {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                          {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                          {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l6_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

                          {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                          {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},

                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l7_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                          {0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0},
                          {0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                          {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0},
                          {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
                          {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1},
                          {0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                          {0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
                          {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l8_15(int array[15][15])
{
    int values[15][15] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
                          {0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
                          {0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0},
                          {0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                          {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                          {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},
                          {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                          {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
                          {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                          {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l9_15(int array[15][15])
{
    int values[15][15] = {{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                          {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                          {1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1},
                          {0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0},
                          {0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                          {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                          {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
                          {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                          {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                          {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},};

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}

void l10_15(int array[15][15])
{
    int values[15][15] = {{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                          {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
                          {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                          {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                          {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                          {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
                          {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                          {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                          {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},};
                          
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            array[i][j] = values[i][j];
}