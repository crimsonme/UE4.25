// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Input/SComboBox.h"

class SComboButton;
class ISessionSourceFilterService;
class FWorldObject;

class SWorldTraceFilteringWidget : public SCompoundWidget
{
public:
	/** Default constructor. */
	SWorldTraceFilteringWidget() {}

	virtual ~SWorldTraceFilteringWidget() {}

	SLATE_BEGIN_ARGS(SWorldTraceFilteringWidget) {}
	SLATE_END_ARGS()

	/** Begin SCompoundWidget overrides */
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	/** End SCompoundWidget overrides */

	void Construct(const FArguments& InArgs);
	void SetSessionFilterService(TSharedPtr<ISessionSourceFilterService> InSessionFilterService);
protected:
	void RefreshWorldData();
	TSharedRef<SWidget> OnGetMenuContextMenu();

protected:
	/** Session service used to retrieve state and request filtering changes */
	TSharedPtr<ISessionSourceFilterService> SessionFilterService;

	/** Latest set of retrieve World Objects from SessionFilterService */
	TArray<TSharedPtr<FWorldObject>> WorldObjects;

	/** Listview widget used to display WorldObjects  */
	TSharedPtr<SListView<TSharedPtr<FWorldObject>>> WorldListView;

	TSharedPtr<SComboButton> OptionsComboBox;

	/** Cached timestamp, at which WorldObjects was last updated */
	FDateTime TimeStamp;
};