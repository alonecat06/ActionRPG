﻿// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include "CoreMinimal.h"
#include "IDirectoryWatcher.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnLuaEditorFunctionLibrary.generated.h"

UCLASS()
class UNLUAEDITOR_API UUnLuaEditorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void WatchScriptDirectory();

	static void FetchNewVersion();

	static FString GetCurrentVersion();

private:
	static void OnLuaFilesModified(const TArray<FFileChangeData>& FileChanges);

	static FDelegateHandle DirectoryWatcherHandle;
};
