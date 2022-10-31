#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
typedef unsigned int uint;

enum ctype {
	WARRIOR = 00,
	WIZARD  = 01,
	ARCHER  = 10,
	PRIEST  = 11
};

typedef struct {
	char name[1000];

	union {
		uint id;
		struct {
			uint idType : 2;
		};
	};

	union {
		uint level;	
	};

	union {
		uint hp;
		struct {
			uint hpType : 2;
		};
	};

	union {
		uint abil;
		uint st;
		uint mp;
		uint ar;
		uint pr;
	};

}character ;
int setCharInfo(character* _char) {
	uint type;

	printf("select type: 0.Warrior 1.Wizard 2.Archer 3.Priest : ");
	scanf("%d", &type);

	_char->id = 1000;
	if (type == 0) {
		_char->idType = WARRIOR;
	}

	printf("Enter [name] [hp] [st|mp|ar|pr] : ");
	scanf("%s %d %d", &_char->name, &_char->hp, &_char->abil);

	return 0;
}


int levelUp(character* _char) {
	_char->level++;
	_char->hp = _char->hp * 1.1;
	_char->abil = _char->abil*1.1;

	return 0;
}

void printCharInfo(character* _char) {
	//uint type;

	
	printf("[Name] %s [ID] %u [%s, Lv.%d] [HP] %u", _char->name, _char->id, _char->idType, _char->level, _char->hp);

	if(_char->idType == 00){
		printf("[ST]");
	}
	else if (_char->idType == 01) {
		printf("[MP]");
	}
	else if (_char->idType == 10) {
		printf("[AR]");
	}
	else if (_char->idType == 11) {
		printf("[PR]");
	}
	else {

	}
		printf("%u \n", _char->abil);
}


int main() {
	int i;
	character user = {0};//error

	setCharInfo(&user);
	printCharInfo(& user);
	for (i = 0; i < 5; i++) {
		levelUp(&user);
		printCharInfo(&user);
	}
		return 0;
}
//ref . https://dojang.io/mod/page/view.php?id=454