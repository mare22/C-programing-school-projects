#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 * Mini RPG game represent unknow hero who fight vs enemy in the world of swords and magic.
 * Both participants starts with 100 helth and fight is finished when somebody's helth fall
 * to 0 or less.
 *
 * In every cycle player has choice to attack with sword or lightening, chosing the number
 * 1 or 2.
 * 
 * If player choses the sword, has 80% chance to hit and dealing 10-15 damage.
 * If player choses the lightening, has 50% chance to hit and dealing 20-30 damage.
 * If player miss, then health stays unchanged.
 * 
 * After each choice and attack enemy attack and deal 10 damage to hero.
 */

void printHP(int heroHelth, int enemyHelth)
{
        printf("\n");
        printf("==============================================");
        printf("\n");

        printf("Hero have %d HP\n", heroHelth);
        printf("Enemy have %d HP\n", enemyHelth);
}

int inputChoice(int *choice)
{
    printf("\n");
    printf("1 - Sword attack (80 %% hit, 10-15 dmg)\n");
    printf("2 - Lightening attack (50 %% hit, 20-30 dmg)\n");
    printf("\n");
    printf("Your choice: ");
    scanf("%d", choice);
}

int lightingAttack()
{
    int random = rand() % 10 + 1;

    //If the random number is equal or higher then 8, then we hit enemy.
    if(random <= 5)
    {
        //We can deal damage from 20-29
        int damage = (rand() % 10) + 20;

        printf("Lightening attack! We deal %d damage to enemy\n", damage);
        
        return damage;
    }
    
    printf("Attack missed!\n");

    return 0;
}

int swordAttack()
{
    int random = rand() % 10 + 1;

    //If the random number is equal or higher then 8, then we hit enemy.
    if(random <= 8) {
        //We can deal damage from 10-15
        int damage = (rand() % 6) + 10;

        printf("Sword attack! We deal %d damage to enemy\n", damage);

        return damage;
    }

    printf("Attack missed!\n");

    return 0;
}

int main()
{
    srand(time(0));

    int random, dmgSword, dmgLightening;
    int choice, heroHelth=100, enemyHelth=100;

    printf("=================================================\n");
    printf("Lightening and Sword - by Marko Obrenic S30/17\n");
    printf("=================================================\n");

    do {
        printHP(heroHelth, enemyHelth);
        inputChoice(&choice);

        if(choice == 1) {
            enemyHelth -= swordAttack();
        } else if(choice == 2) {
            enemyHelth -= lightingAttack();
        } else {
            printf("Ups! You took wrong command!\nTry again\n");
        }

        if(enemyHelth > 0) {
            printf("Enemy attack hero and deal 10 damage\n");
            heroHelth -= 10;
        }
    } while(heroHelth > 0 && enemyHelth > 0);


    if(heroHelth<=0) {
        printf("\n\nHero is died!!\nGame over!\n\n");
    } else {
        printf("\n\nThe enemy is defeated!!!\n\n");
    }


    return 0;
}
